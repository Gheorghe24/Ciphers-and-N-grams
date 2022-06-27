## Tema2 - Templul magic

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
In cadrul celui de-al doilea task am inceput de asemenea prin a-mi defini niste constante si functii care imi vor folosi in cadrul programului. 

Am citit cele 3 stringuri de care aveam nevoie la taskurile 2.1 si 2.2 (cifrul, cheia si mesajul pe care aveam sa-l decriptez cu ajutorul acestei chei) si ulterior am mai citit un string pentru cifrul "addition".

Pentru taskul 2.1 am transformat mesajul intr-un numar si am folosit subprogramul definit mai sus numit "decriptare_c" pentru a-l decodifica si a-l salva in vectorul de caractere s.

Decriptare_C:
-------------
In aceasta functie am 3 for-uri(pentru litere mari, mici si cifre) in care "rotesc" fiecare caracter cu cheia "nr" si ma asigur de fiecare data ca raman cu acelasi tip de caracter (litera mica, mare sau cifra).

Decriptare_V:
------------
In cadrul decodificarii Vigenere am creat functia "decriptare_v" dar inainte sa o apelez imi "prelungesc" cheia pentru a avea aceeasi dimensiune cu mesajul pe care il decriptez. 

In interiorul functiei declar un vector in care salvez literele majuscule ca pozitia lor din alfabet.
"For-urile" au acelasi scop ca cele folosite in functia precedenta si singurul lucru care difera aici
e faptul ca cheia cu care "rotesc" fiecare caracter se schimba de fiecare data in functie de elementele
vectorului creat mai sus numit "nrMaj".

Cel de-al 3-lea subpunct din cadrul acestui task se complica putin insa e vorba de adunarea simpla dintre 2 numere,
cu retinerea cifrei 1 si adunarea acestora cifra cu cifra. 
Mai intai de toate, dupa ce am citit si ce-al doilea mesaj(numar citit ca string) a trebuit sa decriptez aceste 2 numere
cu ajutorul cifrului Caesar, folosind functia "decriptare_c".

Am interschiombat sirurile intre ele in cazul in care cel de-al doilea numar ar fi fost cel mai lung si le-am inversat
pentru a aduna astfel toate cifrele de la final(Mi-am creat o functie strrev care imi inverseaza un sir de caractere 
dat ca parametru).

Am adunat cu ajutorul a 2 for-uri(unul care merge pana la lungimea sirului mai mic si celalalt pentru adunarea cifrelor 
ramase de la sirul cu lungime mai mare).
Am avut grija sa salvez in cazul in care cele 2 cifre adunate treceau 
peste 9 si adunam astfel de fiecare data si cu "c" in cadrul vectorului de cifre numit "rez". 

Variabila "c" devenea 1 in cazul in care rezultatul era mai mare decat 10 si se reseta la 0 cand cele 2 cifre adunate dadeau
un numar mai mic decat 10.
La finalul acestor 2 structuri repetitive erau sanse in care am fi ramas cu "1 in minte" si trebuia sa mai adaug cifra 1 
in vectorul rezultat.
Am inversat acest vector de numere numit "rez" si am tratat si cazurile in care as fi avut doar cifre de 0 la inceputul numarului rezultat apoi am afisat acest numar.

Task 3
--------
La taskul 3 am inceput prin a declara stringuri si matrice de stringuri pe care le voi folosi ulterior in rezolvare.
Pentru a citi mai multe linii de cuvinte am folosit un "while" cu ajutorul caruia ma intreb de fiecare data daca mai pot citi o linie sau am ajuns la finalul fisierului. Cu ajutorul functiei strtok am salvat fiecare cuvant in matricea de charuri numita "text". Am declarat mai apoi variabile de tip indici sau "semafor" cu care aveam sa aflu mai intai numarul de 2-grame din cadrul textului.Cu ajutorul a 2 indici (i si j) am inceput sa compar 2 cate 2 cuvinte si am salvat numarul de aparitii a fiecarei 2-grame cu ajutorul contorului "c".Pentru a afisa o singura data 2-gramele am retinut pe parcurs ce comparam in matricea "gasit" 2-gramele.Astfel ma intrebam de fiecare data daca acestea au aparut in matricea "gasit" si treceam mai departe in cazul afirmativ.Am reinitializat vectorul de stringuri "gasit" si am repetat aceleasi operatii insa de data aceasta am afisat 2-gramele si numarul de aparitii ale acestora.Codul nu e cel mai eficient,se repeta o mare parte din program dar functioneaza. 
