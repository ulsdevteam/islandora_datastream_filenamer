# islandora_datastream_filenamer

## Install:

This module needs a patch to be applied to the core islandora module. The required patch "0001-added-module_invoke_all-call-to-create_datastream_fi.patch" is included as a file in this module.  To apply the patch file:

1) move the file to the islandora folder

2) From that folder, apply the patch with: 

**$ git apply -v 0001-added-module_invoke_all-call-to-create_datastream_fi.patch**

After the patch has been applied, the normal islandora datastream code in islandora_view_datastream() will be able to get a filename from this new islandora_datastream_filenamer module.

### Usage

Configure the filename tokens at admin/islandora/tools/islandora_datastream_filenamer (user needs to have "Administer Site Configuration" permission).  Select any of the tokens to create the filename pattern.  Any of the tokens can be used, but a section pertaining to Fedora Datastreams contains tokens that can be replaced with the specific values from the datastream or the object that the datastream belongs to.  These contain: Datastream's ID [dsfilename:id], Datastream's label [dsfilename:ds-label], Extension from Datastream's Mimetype [dsfilename:fileextension], Fedora object PID [dsfilename:pid], Fedora object label [dsfilename:label], Fedora object namespace [dsfilename:namespace], Fedora short PID [dsfilename:shortpid].

The filename pattern can contain any separation characters (that are legal in a filename) such as:
**[dsfilename:id]_[dsfilename:label].[dsfilename:fileextension]** results in filenames like: 
"MODS_Records of First Trinity Evangelical Lutheran Church (Pittsburgh, Pa.), 1837-1975.xml"

**[dsfilename:id]__[current-user:ip-address]_[current-date:custom:Ymd].[dsfilename:fileextension]** results in filenames like: "DC__130.49.185.138_20170413.xml".

Any special characters that can not be used for a filename are replaced with a "-" character.

## Author / License

Written by Willow Gillingham for the [University of Pittsburgh](http://www.pitt.edu).  Copyright (c) University of Pittsburgh.

Released under a license of GPL v2 or later.
