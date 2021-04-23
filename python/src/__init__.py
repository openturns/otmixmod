"""
    otmixmod --- The Mixmod interface for Open TURNS
    ===================================================

    Contents
    --------
      'otmixmod' is a python module for Open TURNS that allows to use
      the Mixmod software to build Open TURNS objects.

"""

import sys
if sys.platform.startswith('win'):
    # this ensures OT dll is loaded
    import openturns

from .otmixmod import *

__version__ = '0.12'
