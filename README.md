# C++ מימוש קטאן ב

## הסבר על התאמת החוקים למימוש שלי
-`trade`: השחקן בעל התור הנוכחי בוחר איזה משאבים הוא רוצה לתת ולקבל ועם איזה שחקן לבצע את ההחלפה ובמידה ולשני השחקנים יש את המשאבים הנדרשים הטרייד יתבצע

-`knight`: בהתאם להנחיות במטלה, אין שימוש באביר אלא על מנת לאסוף אותו כדי לקבל את קלף הצבא הכי גדול

## My board:

My catan board is represented by two vectors.
The first one is a vector of structurePlace objects of size 54 and vector roadPlaces of size 72. the structurePlaces vector represents the nodes and the roadPlaces vector represents the edges of the board.
Each node and edge on the board were assigned a number, and the road/structure that represents them will be accessed through the vector in their matching number in the vectors, for example if i want to access node number 12 i will go to structurePlaces[12].

this is how the board is referred to:
-each `Yellow` number represents the number of the node in the structurePlace vector.
-each `Blue` number represents the number of the edge in the roadPlace vector.
![image](https://github.com/benami171/System_Programming2_Exe3/assets/102553622/fca93a22-6bbf-4340-90fd-3be06fadc4de)

