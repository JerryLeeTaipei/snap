#!/bin/bash
#
# Copyright (C) 2016 Canonical Ltd
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

set -e

TESTS_EXTRAS_URL="https://git.launchpad.net/~snappy-hwe-team/snappy-hwe-snaps/+git/tests-extras"
TESTS_EXTRAS_PATH=".tests-extras"

# Display help.
# This has to be in sync with the tests-extras/test-runner.sh script
# functionalities as the parameters to this one are passed directly there
# this function will quit the script because of the 'exec' keyword
show_help() {
    exec cat <<'EOF'
Usage: run-tests.sh [OPTIONS]

This is fetch & forget script and what it does is to fetch the
tests-extras repository and execute the run-tests.sh script from
there passing arguments as-is.

optional arguments:
  --help                           Show this help message and exit
  --channel=<channel>              Select another channel to build the base image from (default: $channel)
  --snap=<name>                    Extra snap to install
  --debug                          Enable verbose debugging output
  --test-from-channel=<channel>    Pull snap from the specified channel instead of building it from source
  --spread-system=<system>         Name of a spread system to use for testing
  --spread-filter=<filter>         Spread filter expressions for test cases
  --external-address=<IP address>  Address of external backend used for testing
  --external-user=<user name>      User name to use on external test backend (default: $external_user)
  --external-password=<password>   Password to use for specified external user (default: $external_password)
  --force-new-image                Force generating a new image used for testing
  --image-unsigned-core            Use an unsigned core snap for the generated image
  --image-unsigned-gadget          Use an unsigned gadget snap for the generated image
  --image-unsigned-kernel          Use an unsigned kernel snap for the generated image
EOF
}

# Clone the tests-extras repository
clone_tests_extras() {
	echo "INFO: Fetching tests-extras scripts into $TESTS_EXTRAS_PATH ..."
	(git clone -b master $TESTS_EXTRAS_URL $TESTS_EXTRAS_PATH >/dev/null 2>&1)
	if [ $? -ne 0 ]; then
		echo "ERROR: Failed to fetch the $TESTS_EXTRAS_URL repo, exiting.."
		exit 1
	fi
}

# Make sure the already cloned tests-extras repository is in a known and update
# state before it is going to be used.
restore_and_update_tests_extras() {
	echo "INFO: Restoring and updating $TESTS_EXTRAS_PATH"
	(cd $TESTS_EXTRAS_PATH && git reset --hard && git clean -dfx && git pull)
	(cd ..)
}

# ==============================================================================
# This is fetch & forget script and what it does is to fetch the tests-extras
# repo and execute the run-tests.sh script from there passing arguments as-is.
#
# The tests-extras repository ends up checked out in the snap tree but as a
# hidden directory which is re-used since then.

# Display help w/o fetching anything
if [ "$1" == "--help" ]; then
	show_help
	exit 0
fi

if [ -d "$TESTS_EXTRAS_PATH" ]; then
	restore_and_update_tests_extras
else
	clone_tests_extras
fi

# Any project-specific options for test-runner should be specified in
# .tests_config
if [ -e ".tests_config" ]; then
    . .tests_config
fi

echo "INFO: Executing tests runner"
cd $TESTS_EXTRAS_PATH && ./tests-runner.sh "$@" "$EXTRA_ARGS"
