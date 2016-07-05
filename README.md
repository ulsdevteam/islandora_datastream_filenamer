# islandora_datastream_filenamer

Copyright 2016 (c) University of Pittsburgh

Licensed under GPL 2 or better.


## Install:

This module needs a patch to be applied to the core islandora module. The required patch "0001-added-module_invoke_all-call-to-create_datastream_fi.patch" is included as a file in this module.  To apply the patch file:

1) move the file to the islandora folder

2) From that folder, apply the patch with: 

**$ git apply -v 0001-added-module_invoke_all-call-to-create_datastream_fi.patch**

After the patch has been applied, the normal islandora datastream code in islandora_view_datastream() will be able to get a filename from this new islandora_datastream_filenamer module.
