#! /bin/bash -f
#
#
# MegaRAID 9262 OEM driver for solaris
#
DRV=mr_sas_il

DEVLIST=()

DEVLIST+=("pciex1000,5d.1000.9364")	# NEC N8103-177
#DEVLIST+=("pciex1000,5d")		# NEC N8103-177

echo "DEVLIST: ${DEVLIST[@]}"

DEVLIST2=()
for i in "${DEVLIST[@]}"
do
	pcidev=`grep $i /etc/driver_aliases`
	echo $pcidev
	if [ "$pcidev" == "" ] ; then
		DEVLIST2+=("$i")
	fi
	echo $i
done

echo DEVLIST2: "${DEVLIST2[@]}"

if [ "${DEVLIST2[@]}" == "" ] ; then
	echo nothing to do.
	exit 1
fi

set existing = `grep "${DRV} " /etc/driver_aliases`
echo $existing
exit

if [ "$existing" == "" ] ; then
	/usr/sbin/add_drv -n -v -m '* 0600 root sys' -i "$DEVLIST2" ${DRV}
else 
	/usr/sbin/update_drv -a -v -m '* 0600 root sys' -i "$DEVLIST2" ${DRV}
fi

sync
