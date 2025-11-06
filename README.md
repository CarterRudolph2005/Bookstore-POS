<h1>Bookstore POS in C++</h1>

<h2>General Description</h2>
This C++ project is a Bookstore Inventory Manager demonstrating Object-Oriented Programming (OOP) principles. The Book class is used to store details like title, author, genre, and price, and the Store class to manage the inventory using a dynamically allocated array of books. The program allows users to add, sell, find, display, and sort books, while automatically resizing the underlying array as needed to accommodate new inventory. This system effectively models basic retail operations, including tracking the number of books and the cash in the register.

<h2>Languages/Frameworks Used</h2>

 - <b>C++</b>

<h2>Technical Skills</h2>
<ul>
  <li>Dynamic Memory Management and Arrays: Implemented a dynamically allocated array of Book objects (`Book* bookInventory`). This required using the `new` and `delete[]` operators in the `Store` class constructor and destructor, respectively, to manage heap memory. </li>
  <li>Dynamic Array Resizing: Developed a `resizeList` function to handle capacity issues. This involves creating a new, larger array, deep copying the existing Book data into the new array, and deleting the old one, showcasing a practical application of dynamic memory concepts beyond simple allocation. </li>
  <li> Object-Oriented Programming Fundamentals: Utilized classes (`Book` and `Store`) to model real-world entities, employed encapsulation (private member variables accessed via public getter/setter methods), and managed member initialization using both constructors and an initializer list. </li>
  <li> String Manipulation and C-Style Strings: Used standard C-string functions like `strncpy` and `strcmp` to handle title and author names, including safe copy practices to prevent buffer overflows (e.g., in `Book::Set`). </li><li> Algorithms: Applied a simple linear search (`findBookIndex`) to locate books and implemented a bubble sort algorithm (`sort`) to organize the inventory by title or author, demonstrating basic sorting and searching skills. </li>
</ul>
