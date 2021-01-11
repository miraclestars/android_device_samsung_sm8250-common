[AID_VENDOR_QTI_DIAG]
value:2901

[AID_VENDOR_QDSS]
value:2902

[AID_VENDOR_RFS]
value:2903

[AID_VENDOR_RFS_SHARED]
value:2904

[AID_VENDOR_ADPL_ODL]
value:2905

[AID_VENDOR_QRTR]
value:2906

[AID_VENDOR_THERMAL]
value:2907

[AID_VENDOR_FASTRPC]
value:2908

[product/vendor_overlay/*/bin/*]
mode: 0755
user: AID_ROOT
group: AID_SHELL
caps: 0

[system/vendor/bin/loc_launcher]
mode: 0755
user: AID_GPS
group: AID_GPS
caps: SETGID SETUID

[system/vendor/bin/pd-mapper]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[system/vendor/bin/pm-service]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[vendor/bin/loc_launcher]
mode: 0755
user: AID_GPS
group: AID_GPS
caps: SETGID SETUID

[vendor/bin/pd-mapper]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[vendor/bin/pm-service]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[bt_firmware/]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[carrier/]
mode: 0771
user: AID_SYSTEM
group: AID_RADIO
caps: 0

[dqmdbg/]
mode: 0770
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[dsp/]
mode: 0771
user: AID_MEDIA
group: AID_MEDIA
caps: 0

[efs/]
mode: 0771
user: AID_SYSTEM
group: AID_RADIO
caps: 0

[firmware/]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[firmware/image/*]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[firmware-modem/]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[keydata/]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[keyrefuge/]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[metadata/]
mode: 0771
user: AID_ROOT
group: AID_SYSTEM
caps: 0

[optics/]
mode: 0771
user: AID_ROOT
group: AID_SYSTEM
caps: 0

[persist/]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[prism/]
mode: 0771
user: AID_ROOT
group: AID_SYSTEM
caps: 0

[spu/]
mode: 0770
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[vendor/firmware_mnt/image/*]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0
