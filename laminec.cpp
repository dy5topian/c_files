
#include <iostream>
#include<graphics.h>
struct Point {
    float x;
    float y;
    char color[10];
};
struct Point_node {
    Point* data;
   Point_node* precedent;
   Point_node* suivant;
};
struct animal{
    float poids;
    float hauteur;
    char nom[20];
};
struct animal_node{
    animal* data;
   animal_node* precedent;
   animal_node* suivant;
};
class erreur{};
Point * createpoint(){
        Point* point=new Point;
        printf("enter les informations de point !\n");
        printf("x: ");
        scanf("%f",&point->x);
        printf("y: ");
        scanf("%f",&point->y);
        printf("color: ");
        scanf("%s",point->color);
        printf("-------------votre point etait cree--------\n");
        return point;

}
animal* define_animal(){
        animal* anim =new animal;
        printf("enter les informations de point !\n");
        printf("hauteur: ");
        scanf("%f",&anim->hauteur);
        printf("poids: ");
        scanf("%f",&anim->poids);
        printf("nom scientifique: ");
        scanf("%s",anim->nom);
       animal_node* newNode = new animal_node;
        newNode->data = anim;
        newNode->suivant = nullptr;
        printf("-------------votre point etait cree--------\n");
        return anim;

}
class DoubleLinkedList_animal {
private:
   animal_node* head;
   animal_node* tail;

public:
    DoubleLinkedList_animal() {
        head = nullptr;
        tail = nullptr;
    }
        
    void ajouter_animal() {
        animal* anim=define_animal();
       animal_node* newNode = new animal_node;
        newNode->data = anim;
        newNode->suivant = nullptr;

        if (head == nullptr) {
            newNode->precedent = nullptr;
            head = newNode;
            tail = newNode;
        } else {
            newNode->precedent=tail;
            tail->suivant = newNode;
            tail = newNode;
        }
    }

    void update_animal_data(animal* newAnimal) {
        int index;
        printf("entrer l'index de l'animal que vous voulez updatee ses data: ");
        scanf("%d",&index);
       animal_node* currentNode = head;
        int currentIndex = 0;

        while (currentNode != nullptr && currentIndex != index) {
            currentNode = currentNode->suivant;
            currentIndex++;
        }

        if (currentNode != nullptr) {
            currentNode->data = newAnimal;
        } else {
            std::cout << "Invalid index." << std::endl;
        }
    }

    void free_animal() {
        int index;
        printf("entrer l'index de l'animal a liberee ");
        scanf("%d",&index);

       animal_node* currentNode = head;
        int currentIndex = 0;

        while (currentNode != nullptr && currentIndex != index) {
            currentNode = currentNode->suivant;
            currentIndex++;
        }

        if (currentNode != nullptr) {
            if (currentNode->precedent != nullptr) {
                currentNode->precedent->suivant = currentNode->suivant;
            } else {
                head = currentNode->suivant;
            }

            if (currentNode->suivant != nullptr) {
                currentNode->suivant->precedent = currentNode->precedent;
            } else {
                tail = currentNode->precedent;
            }

            delete currentNode;
        } else {
            printf("Invalide syntax");
        }
    }
    
    void affiche_animal(int index){

       animal_node* currentNode = head;
        int currentIndex = 0;

        while (currentNode->suivant!= nullptr && currentIndex != index) {
            currentNode = currentNode->suivant;
            currentIndex++;
        }
        if (currentIndex==index){
            std::cout << "animal  "<<index<<" : +poids: " << currentNode->data->poids << ", +hauteur: " << currentNode->data->hauteur << ", +nom scientifique: "<<currentNode->data->nom<< std::endl;

        }else{ printf("ce point n'exit pas!\n");}
        
    }
    
    void affiche_liste_animaux() {
      int c=0;
       animal_node* currentNode = head;
        printf("______________________________________________________________________________________________________\n");

        while (currentNode != nullptr) {
            affiche_animal(c);
            currentNode = currentNode->suivant;
            c++;
        }
        printf("_______________________________________________________________________________________________________\n");
    }
};

class DoubleLinkedList {
private:
   Point_node* head;
   Point_node* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }   
    void ajouter_point() {
        Point* point=createpoint();
       Point_node* newNode = new Point_node;
        newNode->data = point;
        newNode->suivant = nullptr;

        if (head == nullptr) {
            newNode->precedent = nullptr;
            head = newNode;
            tail = newNode;
        } else {
            newNode->precedent = tail;
            tail->suivant = newNode;
            tail = newNode;
        }
    }
    
    //modify a point  by replacing it with a new created one
    void modifier_point(Point* newPoint) {
        //scan the index , 
        int index;
        printf("entrer l'index de point que vous voulez moudifier: ");
        scanf("%d",&index);
        //starting from our head ofc
       Point_node* currentNode = head;
       //counter 
        int currentIndex = 0;

        //loop through the list ,as long a s we haven't reached blasa khawia , if so invalide index else we replace that point with the created point.
        while (currentNode != nullptr && currentIndex != index) {
            currentNode = currentNode->suivant;
            currentIndex++;
        }
        //here we assume we have found the index and it's not empty then we modify the value
        if (currentNode != nullptr) {
            currentNode->data = newPoint;
        } else {
            printf("Invalid index.");
        }
    }

    void supprimer_point() {
        //here same steps as modify point 
        int index;
        printf("entrer l'index de point que tu veux supprimer: ");
        scanf("%d",&index);

       Point_node* currentNode = head;
        int currentIndex = 0;

        while (currentNode != nullptr && currentIndex != index) {
            currentNode = currentNode->suivant;
            currentIndex++;
        }
        //assuming we have found the index,not a nullptr ofc
        if (currentNode != nullptr) {
            if (currentNode->precedent != nullptr) {
                currentNode->precedent->suivant = currentNode->suivant;
            } else {
                head = currentNode->suivant;
            }

            if (currentNode->suivant != nullptr) {
                currentNode->suivant->precedent = currentNode->precedent;
            } else {
                tail = currentNode->precedent;
            }

            delete currentNode;
        } else {
            printf("Invalide syntax");
        }
    }

    void affiche_point(int index){

       Point_node* currentNode = head;
        int currentIndex = 0;

        while (currentNode->suivant!= nullptr && currentIndex != index) {
            currentNode = currentNode->suivant;
            currentIndex++;
        }
        if (currentIndex==index){
            std::cout << "Point "<<index<<" : (" << currentNode->data->x << ", " << currentNode->data->y << ",color: "<<currentNode->data->color<<")"<< std::endl;

        }else{ printf("ce point n'exit pas!\n");}
        
    }
    void affiche_liste() {
      int c=0;
       Point_node* currentNode = head;
        printf("______________________________________________________________________________________________________\n");

        while (currentNode != nullptr) {
            
            std::cout << "Point "<<c<<" : (" << currentNode->data->x << ", " << currentNode->data->y << ",color: "<<currentNode->data->color<<")"<< std::endl;
            currentNode = currentNode->suivant;
            c++;
        }
        printf("_______________________________________________________________________________________________________\n");
    }
    friend void plotPoints(DoubleLinkedList& pointList);
};
int validation_choix(int* x,int mx,int mn){
    try{
        std::string input;
        std::cin >> input;

        // Check if the input is numeric
        bool isNumeric = true;
        for (char c : input) {
            if (!std::isdigit(c)) {
                isNumeric = false;
                break;
            }
        }

        if (isNumeric) {
            *x= std::stoi(input);  // Convert the input to an integer
        } else {
            throw erreur();
        }
    
    if (*x>mx or *x<mn){
        throw erreur();
    }
    }
    catch(erreur er){
        printf("_________________votre choix n'est pas valide,veuillez essayer autre fois!______________________\n");
        return 0;

    }
    return 1;
}
void plotPoints(DoubleLinkedList& pointList) {
    printf("ploting tous les pint de la list ....loading.....");
   int maxX = 0;
    int maxY = 0;

    // Find maximum x and y coordinates in the list
   Point_node* currentNode = pointList.head;

    while (currentNode != nullptr) {
        if (currentNode->data->x > maxX)
            maxX = currentNode->data->x;

        if (currentNode->data->y > maxY)
            maxY = currentNode->data->y;

        currentNode = currentNode->suivant;
    }

    int screenWidth = maxX + 800;  // Add some margin for better visualization
    int screenHeight = maxY + 600;

    initwindow(screenWidth, screenHeight, "Point List");
    setbkcolor(WHITE);
     // Clear the screen with the background color
   cleardevice();
    // Set the desired grid properties
   int gridSize = 10;
   int canvasWidth = getmaxx();
   int canvasHeight = getmaxy();
   
   int x, y;
    setcolor(GREEN);
   // Draw horizontal lines
   for (y = gridSize; y < canvasHeight; y += gridSize) {
       line(0, y, canvasWidth, y);
   }

   // Draw vertical lines
   for (x = gridSize; x < canvasWidth; x += gridSize) {
       line(x, 0, x, canvasHeight);
   }

    currentNode = pointList.head;

    while (currentNode != nullptr) {
        int x = (currentNode->data->x)*10;
        int y = (currentNode->data->y)*10;
        int radius = 5;  // Adjust the radius to make the points larger

        // Calculate the coordinates for the circle's bounding rectangle

        // Draw a filled circle
        setfillstyle(SOLID_FILL,RED);  // Adjust the color of the points if needed
        fillellipse(x, y, 5, 5);
      //enum colors::YELLOW
        currentNode = currentNode->suivant;
    }


    getch();  // Delay to display the window for 5 seconds

    closegraph();
}

int main() {
    label0:
    int cx=0;
    printf("bonjour dans notre programme , on offre au moment 2 services , veuillez choisir entre eux.\n");
    printf("1-visualisation des points dans un graphe !\n");
    printf("2-control des animaux dans un zoo !\n");

    //validation_choix(&cx,2,1);
    if(validation_choix(&cx,2,1)!=1){goto label0;}
    if(cx==1){

    DoubleLinkedList pointList;
    label:
    int choix=0;
    while (choix!=7){
    printf("bienvenue a mon program PLOTO ! choisi l'un des fonctionalite au-dessous.. \n\n");
    printf("1-create a new point et l'ajouter a la list ?\n");
    printf("2-affichier un point de la list ? ?\n");
    printf("3-affichier tous le point de la list ?\n");
    printf("4-modifier une point?\n");
    printf("5-plot des points dans un graphe?\n");
    printf("6-suppression d'une point ?\n");
    printf("7-exit.\n\n");
    printf("lamine@choice$ ");
    //take the input as sting.
    if(validation_choix(&choix,7,0)!=1){goto label;}
   
    
    //switch_over
    switch(choix){
    case 1:{
        pointList.ajouter_point();
        break;
    }
    case 2:{
        printf("entrer l'indice d'un  point a afficher: ");
        int i;
        scanf("%d",&i);
        printf("------------------------------------------------------------------------\n");
        pointList.affiche_point(i);
        printf("------------------------------------------------------------------------\n");
        break;
    }
    case 3:{
        pointList.affiche_liste();
        printf("-------------------------------------------------------------------------\n");
        break;
    }
    case 4: {
        pointList.modifier_point(createpoint());
        break;
    }
    case 6: {
        pointList.supprimer_point();
        printf("le point a etait supprimer avec success! \n");
        break;
    }
    case 5:{
        plotPoints(pointList);
        break;
    }
    case 7:{
        printf("exiting the program...loading...byby !");
        break;
    }
                }
    }
    }
    else{
    DoubleLinkedList_animal pointList;
    label2:
    int choix=0;
    while (choix!=7){
        
    printf("bienvenue au program ZOO_CONTROL  ! choisi l'une des fonctionalite au-dessous.. \n\n");
    printf("1-ajouter un nouveau animal au zoo ?\n");
    printf("2-afficher les information d'un animal?\n");
    printf("3-affichier tous les animal?\n");
    printf("4-modifier les information d'un animal?\n");
    printf("5-free animal ?\n");
    printf("6-exit.\n\n");
    printf("lamine@choice$ ");
    //take the input as sting.
    if(validation_choix(&choix,7,0)!=1){goto label2;}
    
    //switch_over
    switch(choix){
    case 1:{
        pointList.ajouter_animal();
        break;
    }
    case 2:{
        printf("entrer l'indice de l'animal a afficher: ");
        int i;
        scanf("%d",&i);
        printf("------------------------------------------------------------------------\n");
        pointList.affiche_animal(i);
        printf("------------------------------------------------------------------------\n");
        break;
    }
    case 3:{
        pointList.affiche_liste_animaux();
        printf("-------------------------------------------------------------------------\n");
        break;
    }
    case 4: {
        pointList.update_animal_data(define_animal());
        break;
    }
    case 5: {
        pointList.free_animal();
        break;
    }
    case 6:{
        printf("exiting the program...loading...byby !");
        break;
    }
                }
           

    }
    }
 return 0;
}