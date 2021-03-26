#!/usr/bin/env python3
from plainbox.provider_manager import setup, N_

setup(
    name='plainbox-provider-alsa-utils',
    namespace='2017.com.canonical.alsa-utils',
    version="1.0",
    description=N_("Plainbox provider for the alsa-utils snap"),
    gettext_domain="2017_com_canonical_alsa-utils",
)
