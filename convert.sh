#!/bin/bash
#root -l 'convert.C("xx18242151546")'
export file=$(kdialog --getopenfilename /home/onl/Panda/ "HLD data files (*.hld)") 

echo "source ~/.bashrc" > /tmp/qqq
echo 'cd /home/onl/mz-unpacker/' >> /tmp/qqq
echo 'root -l -q "convert.C("\""$file"\"")"' >> /tmp/qqq
echo "rm /tmp/qqq" >> /tmp/qqq

konsole --noclose -e '/bin/bash --rcfile /tmp/qqq' &
#echo root -l "convert.C("\""$file"\"")"
#root -l -q "convert.C("\""$file"\"")"
