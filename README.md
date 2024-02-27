# RouterSimulator
IP packet processing system in C language (Simulation of a router)



							PROJECT REPORT PROGRAMMING II


I proceed in this report to explain in broad strokes the operation of the project and my way of resolution.
 
Configuration File



I have processed this file character by character, for it, I have created functions to simplify the processing, namely:

When reading the file, I have been saving each character in a node structure, then I link all the nodes, later I pass them to character string and finally with that string I create the interface structure. For it I use the functions CreaNodo, Creacadena, EnlazaCaracter, CreaInterfaz.

While I make this process, I check some considerations, like that the number of interfaces read and declared are equal.

Later I must read the ip addresses of each subnet, so, the address, after being read, I save it in a table, and with the name of the subnet I proceed to apply the algorithm described before, but this time saving it in a new structure, IP. After this process, I link each ip address read to the list of interfaces previously created. For this I use the functions, CreaIP, and ComparaEnlazaInterfaz among others.

The relevant error checks at this point, such as checking the non-repetition of the same address or that it does not exceed the address of 255, I do at this point, with the help of the functions CompareAddress and FindAddress.





Input file




In this file, I make a previous reading of the special character '<' and I enter in a loop to process it. I start by processing the interface name with the algorithm I also used for the configuration one.

Afterwards, I process the rest of the line storing everything in a table of at most 1024 positions until line break. Once this is done, I create the data package with CreaPaquete. 

Inside this function I decompose the table into source address, destination address, read length, actual length, data, self-reference and length error and fill the packet with this data.
In the same function, I check for length error.
After creating the packet, I link it to the corresponding interface.



Output file



For the output I have simply limited myself to output on the screen exactly what is explained in the enunciation of the project.





As a personal opinion, I want to say that it has been very gratifying to have finished the project, although, after many hours of work and effort, I didn't even know if I would get it on time after so many consecutive failures.
