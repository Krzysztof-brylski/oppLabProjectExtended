# oppLabProjectExtended
My project on object oriented programing classes, its console excel-like app.
## App provides
1. view stack
2. catching basic exceptions 
3. dedicated error view
4. three cell data types
5. building/saving sheet from/to file
6. 4 basic math action to perform on sheet row or column

 ### View stack
   my project use stack data structure to handle screen changes, when user wants to change view this new view is pused on top of view stack,
   then main view method (View::draw) is executed to perform all action intended for specified screen.
  
   When user wants to go back to previous scrren, currently displayed screen is poped out from stack. then another screen is executed.
   app runs while loop till view stack is empty.
  
 ### Vatching basic exceptions and dedicated error view
  application can catch some user illegal action and call dedicated error view.
  
 ### Three cell data types
  application supports three main cell data types:
  1. string cell
  2. float(double) cell
  3. int cell
  for now performiong actions on string cell is illegal 
