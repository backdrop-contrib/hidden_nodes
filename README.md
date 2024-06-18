Hidden Nodes
======================
This module adds a system similar to publish / unpublished status of nodes
except that this is more granular. The reason that this is needed is so that
you can tell certain roles they can't view nodes while others can.

The issue with publishing status is that there is no grey area, it's
all published or all unpublished. Use this module if you want to be able
to limit what some users see in books and menus but still want others
to have full visibility of that content within the context of the site.

Using this module, pages can be fully or partially hidden. This is easily
managed right in the node edit ui.

hidden_nodes looks for the "view all hidden content" permission when a user tries to
view a node that is marked as hidden.

Installation
------------
- Install this module using the official Backdrop CMS instructions at
  https://docs.backdropcms.org/documentation/extend-with-modules.

- Enable the module in your Backdrop site.

- After installing & enabling the module, navigate to your user access page and assign the
appropriate permissions to the roles you wish to be able to view hidden nodes.

- Check your sites Status Report, you may need to rebuild the Node Access Permissions.

Issues
------
Bugs and feature requests should be reported in the issue queue.

Current Maintainers
-------------------
- Laryn Kragt Bakker https://backdropcms.org/account/laryn
- Greg OToole https://github.com/gto1

Credits
-------
- Ported to Backdrop CMS by Greg OToole https://github.com/gto1
- Ported to Backdrop CMS by Laryn Kragt Bakker https://backdropcms.org/account/laryn
- Originally written for Drupal by Yanickoo https://www.drupal.org/u/yannickoo

License
-------
This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.
