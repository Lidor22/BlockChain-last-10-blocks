# BlockChain last 10 blocks  -Introduction :
As a part of our Embedded Linux course , we developed a software to fetch the 10 latest blocks of the BlockChain.
Our system uses a Bash script to contact https://api.blockcypher.com/v1/btc/main and gets in return the main block of the BlockChain, after that it calculates the 9 previous blocks and display some information about them.
The project was developed in Visual Code using C programming language on Ubunutu 18.04 version.

During this Project we learned elements such as :
* Developing project in Linux environment.
* Working with Bash scripts.
* Creating and using a MakeFile.
* Exporting data to CSV file.
* Creating a shared library in Linux(.so file).
* Getting familliar with BlockChain aspects.
* Using Sed and Grep .

# Our Project:

As mentioned above the system fetches the main block from blockcypher.com api and calculates the rest of the blocks.
There are 4 programs that use the data that we got from the Bash script(it is saved to a simple txt file):
1.printblocks.out – prints the 10 latest blocks from the file to the Linux terminal.
2.printblock.out – prints a specific block by hash or height value (recieves the arguments from the Linux terminal).
3.dbtocsv.out – saves the data into a csv file (the file is called “a.csv”).
4.reload_db.out – reload the 10 latest blocks from blockcypher api(in case there are any changes).

In order to activate the system - please follow the next steps:
1. Run the Bash script called "latestBlocks"
2. Use the MakeFile to compile all the .c/.h and to link them with the shared library(.so).
3. Run each program as you like.
