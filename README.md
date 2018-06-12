# islandora_datastream_filenamer

## Introduction

This module allows site administrators to customize filenames used when downloading a datastream file.

## Installation

Install and enable as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

Configure the filename tokens at `admin/islandora/tools/islandora_datastream_filenamer` (user needs to have "Administer Site Configuration" permission).  Select any of the tokens to create the filename pattern.  Any of the tokens can be used, but a section pertaining to Fedora Datastreams contains tokens that can be replaced with the specific values from the datastream or the object that the datastream belongs to.  These contain: Datastream's ID [dsfilename:id], Datastream's label [dsfilename:ds-label], Extension from Datastream's Mimetype [dsfilename:fileextension], Fedora object PID [dsfilename:pid], Fedora object label [dsfilename:label], Fedora object namespace [dsfilename:namespace], Fedora short PID [dsfilename:shortpid].

The filename pattern can contain any separation characters (that are legal in a filename) such as:
**[dsfilename:id]_[dsfilename:label].[dsfilename:fileextension]** results in filenames like: 
"MODS_Records of First Trinity Evangelical Lutheran Church (Pittsburgh, Pa.), 1837-1975.xml"

**[dsfilename:id]__[current-user:ip-address]_[current-date:custom:Ymd].[dsfilename:fileextension]** results in filenames like: "DC__130.49.185.138_20170413.xml".

## Notes

Any special characters that can not be used for a filename are replaced with a "-" character.

If the module is enabled but no configuration is provided, datastream file names will be unaffected by this module.

Other modules may also modify downloadable datastream file names. To find out if any other modules are doing so, you can use the following drush command: `drush hook islandora_datastream_filename_alter`

## Author / License

Written by Brian Gillingham for the [University of Pittsburgh](http://www.pitt.edu).  Copyright (c) University of Pittsburgh.

Released under a license of GPL v2 or later.
