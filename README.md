# Dorchester_CSCI2270_FinalProject
Final project for data structures

Vail Dorchester

Project Summary:

  For this project, I think I'm going to essentially prompt the user for how many points they want to create, create n random points with x, y values, and link them in a master linked list. From this list, I think I will create a graph with path weights equal to the distance between the points. Then, I'll implement multiple different shortest path algorithms and reorder the linked list several times in order of the shortest path found using each method. I might implement some additional criteria just to make it more interesting, because it's quite possible that all of the shortest paths will be the exact same since they are, after all, the same shortest path. From there I'll just print the output. I might implement a menu where I can create a new set of points or choose different operations to perform on the points from the menu. 

Update: creating a randomized graph turned out to be rather difficult, so instead I used a pre-made graph. This also made it easier to test if the shortest path algorithms were working. The two algorithms that are implemented are Dijkstra's, and Floyd's Algorithm.

How to run:
  currently, you can print the nodes, print the edges, or run dijkstra's or floyd's algorithm. there is a menu and it is pretty self explanatory. There is even an about option if you need help.
  
Dependencies/System requirements:
  as of now, there are no external dependencies or system requirements besides your machine having the c++11 compilers.

Bugs:
  -In the menu, if you type a character or string, it will loop endlessly.
  -The full functionality of storing each solution in a linked list has not been ironed out, and is also open to future improvements.
  -The adjacencyMatrixFunction method is currently empty, but I plan to design and implement my own algorithm as a challenge for myself.
  -If you clear the graph, there is currently no way to get that graph back besides restarting the program.
  -So it works best if you choose a reasonable number of vertices, ie, 10-30. if you add too many it doesnt seem to work and if you add too few it doesn't seem to work.
  -also, given enough points, it is bound to generate one that is roughly at the midpoint of the start and finish. because of this, the shortest path has almost always been a list of just 3 points going from start, to midpoint, to finish. Geometrically this makes sense, but it is boring.
