#! /usr/bin/bash
FT_LINE1=2
FT_LINE2=5
cat /etc/passwd | tr ':' ' ' | awk '{print $1}' | awk 'NR % 2 == 0' | rev | sort -r | awk "NR >=$FT_LINE1 && NR<=$FT_LINE2" | tr '\n' ', ' | sed 's/.$/./g' ; echo
