#!/bin/bash
#root -l 'convert.C("xx18242151546")'
export file=$(kdialog --getopenfilename /home/onl/Panda/ "Calibrated root files (*_calibrated.root)") 

echo "source ~/.bashrc" > /tmp/qqq
echo 'cd /home/onl/Panda/' >> /tmp/qqq
echo 'root -l "/home/onl/mz-unpacker/analyzer.C("\""$file"\"")"' >> /tmp/qqq
echo "rm /tmp/qqq" >> /tmp/qqq

konsole --noclose -e '/bin/bash --rcfile /tmp/qqq' &
#echo root -l "convert.C("\""$file"\"")"
#root -l -q "convert.C("\""$file"\"")"
