#!/bin/bash

counter=1

wget -O lidor https://api.blockcypher.com/v1/btc/main
mainBlock=$(grep 'previous_url' lidor)
set -- $mainBlock
prevUrl="$2"
echo $prevUrl > lidor
prevUrl=$(sed "s/\"//g" lidor) 
echo $prevUrl > lidor
finalUrl=$(sed "s/,//g" lidor) 
wget -O lidor ${finalUrl}

cp /dev/null final10Blocks

for i in 1 2 3 4 5 6 7 8 9 10
do
   temp=$(grep -w 'hash\|height\|total\|time\|relayed_by\|prev_block' lidor)
   echo $temp > oneBlock
   removeGersh=$(sed "s/\"//g" oneBlock) 
   echo $removeGersh > oneBlock
   removeSpace=$(sed "s/ //g" oneBlock) 
   echo $removeSpace > oneBlock  
   cat oneBlock|tr ',' '\n' >>final10Blocks
   #until here i got the wanted data for a specific block

   #now we want to move to the previousBlock
   firstInfo=$(grep 'prev_block_url' lidor)
   set -- $firstInfo
   prevUrlForThisBlock="$2"
   echo $prevUrlForThisBlock > lidor
   prevUrlForThisBlock=$(sed "s/\"//g" lidor) 
   echo $prevUrlForThisBlock > lidor
   finalUrlForThisBlock=$(sed "s/,//g" lidor) 
   wget -O lidor ${finalUrlForThisBlock}

done

rm lidor
rm oneBlock

