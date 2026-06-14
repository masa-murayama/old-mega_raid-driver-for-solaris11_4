#! /bin/bash -v
#

#
# remove lmrc entry for "pciex1000,5d"
#
/usr/sbin/update_drv -d -v -m '* 0600 root sys' -i '"pciex1000,5d"' lmrc

#
# add mr_sas_il entry for "pciex1000,5d"
#
/usr/sbin/add_drv -n -v -m '* 0600 root sys' -i '"pciex1000,5d"' mr_sas_il

sync
