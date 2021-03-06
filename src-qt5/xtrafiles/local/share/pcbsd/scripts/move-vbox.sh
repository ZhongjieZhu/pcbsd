#!/bin/sh

# 1 = USER
# 2 = HOME

# Helper script to move VBOX from /root -> /usr/home/FOO
if [ -e "/usr/local/bin/kdialog" ] ; then
  dbusRef=`kdialog --progressbar "Moving VM's... Please wait..." 0`
  mv "/root/VirtualBox VMs" "${2}/VirtualBox VMs"
  qdbus $dbusRef close
elif [ -e "/usr/local/bin/zenity" ] ; then
  mv "/root/VirtualBox VMs" "${2}/VirtualBox VMs" | zenity --text "Moving VMs... Please wait..." --progress --pulsate --auto-close --no-cancel
fi
chown -R "${1}:${1}" "${2}/VirtualBox VMs"

if [ -d "/root/.VirtualBox" ] ; then
  mv "/root/.VirtualBox" "${2}/.VirtualBox"
  sed -i '' "s|/root/|${2}/|g" "${2}/.VirtualBox/VirtualBox.xml"
  chown -R "${1}:${1}" "${2}/.VirtualBox"
fi

if [ -d "/root/.config/VirtualBox" ] ; then
  mv "/root/.config/VirtualBox" "${2}/.config/VirtualBox"
  sed -i '' "s|/root/|${2}/|g" "${2}/.config/VirtualBox/VirtualBox.xml"
  chown -R "${1}:${1}" "${2}/.config/VirtualBox"
fi
