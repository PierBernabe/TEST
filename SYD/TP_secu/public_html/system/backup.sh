#!/bin/bash
source /home/web/.bash_profile
SD=/home/web/public_html/system/
cd $SD
WD=`/usr/local/bin/unqlite_jx9 $SD/db $SD/r.jx9`
cd $WD
cp $SD/commands $SD/commands.backup
