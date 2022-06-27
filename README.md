## Homework in C - Magic Temple

Task 1
------
At the first task I started by defining some functions that will be useful to me later in solving the problem (maximum, display, mirroring, etc.).

I then declared the variables, the vectors in which I was going to store the directions in which I have to "move in the matrix" and the matrix itself.

With the help of the "strtok" function I divided the second line into words and I wondered for each of which type they are part.

I also needed the "atoll" function to convert the strings to numbers and then perform the operations required for each type of magic word.

Thus, after each magic word, of any type, I had saved in the variable "poz" the numbers corresponding to the 4 directions.
I stored all these positions in a vector called "dir" and I started thinking about crossing the matrix.

I took a repetitive structure of type "for" and for each number read (magic word) 
I move in the matrix,depending on the decoded word, already knowing the "directions" in which I will have to go and also save the number of the movement in the current
position in the matrix

Task 2
----------
In the second task I also started by defining some constants and functions that will be used in the program.

I read the 3 strings I needed for tasks 2.1 and 2.2 (The cipher, the key and the message I was going to decrypt with this key) and then I read another string for the "addition" cipher.

For task 2.1 I turned the message into a number and used the subprogram defined above called "decryption_c" to decode it and save it in the character vector s.

Decriptare_C:
-------------
In this function I have 3 for-loops (for uppercase, lowercase and numbers) in which I "rotate" each character with the key "nr" and I make sure every time I stay with the same type of character (lowercase, uppercase or number) .

Decriptare_V:
------------
During the Vigenere decoding I created the "decrypt_v" function but before I call it I "extend" my key to have the same size as the message I decrypt.

Inside the function I declare a vector in which I save the capital letters as their 
position in the alphabet.
The "for-loops" have the same purpose as those used in the previous function and the 
only thing that differs here is the fact that the key with which they "rotate" each 
character changes each time depending on the elements of the vector created above called "nrMaj".

The 3rd sub-item in this task is a bit complicated but it is a simple addition between 
2 numbers, with the retention of the digit 1 and their addition digit by digit.
First of all, after reading the second message (number read as string) I had to decrypt these 2 numbers using the Caesar Cipher, using the "decryption_c" function.

I swapped the strings together if the second number was the longest and reversed them 
To gather all the numbers at the end I created a strrev function that inverts a string
given as a parameter.

I summed with the help of 2 for-loops (one that goes to the length of the smaller string and the other one for summing numbers left from the longer string).
I took care to save in case the 2 collected numbers passed
over 9 .

Variabila "c" devenea 1 in cazul in care rezultatul era mai mare decat 10 si se reseta la 0 cand cele 2 cifre adunate dadeau
un numar mai mic decat 10.
La finalul acestor 2 structuri repetitive erau sanse in care am fi ramas cu "1 in minte" si trebuia sa mai adaug cifra 1 
in vectorul rezultat.
Am inversat acest vector de numere numit "rez" si am tratat si cazurile in care as fi avut doar cifre de 0 la inceputul numarului rezultat apoi am afisat acest numar.

Task 3
--------
La taskul 3 am inceput prin a declara stringuri si matrice de stringuri pe care le voi folosi ulterior in rezolvare.
Pentru a citi mai multe linii de cuvinte am folosit un "while" cu ajutorul caruia ma intreb de fiecare data daca mai pot citi o linie sau am ajuns la finalul fisierului. Cu ajutorul functiei strtok am salvat fiecare cuvant in matricea de charuri numita "text". Am declarat mai apoi variabile de tip indici sau "semafor" cu care aveam sa aflu mai intai numarul de 2-grame din cadrul textului.Cu ajutorul a 2 indici (i si j) am inceput sa compar 2 cate 2 cuvinte si am salvat numarul de aparitii a fiecarei 2-grame cu ajutorul contorului "c".Pentru a afisa o singura data 2-gramele am retinut pe parcurs ce comparam in matricea "gasit" 2-gramele.Astfel ma intrebam de fiecare data daca acestea au aparut in matricea "gasit" si treceam mai departe in cazul afirmativ.Am reinitializat vectorul de stringuri "gasit" si am repetat aceleasi operatii insa de data aceasta am afisat 2-gramele si numarul de aparitii ale acestora.Codul nu e cel mai eficient,se repeta o mare parte din program dar functioneaza. 
