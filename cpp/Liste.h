#ifndef _LISTE_H_
#define _LISTE_H_
 
#include "LE.h"
#include <cstdlib>
#include <string>
 
template <class type>
class FilterableList
{
 
private:
 
	LE <type>* first;
    LE <type>* last;
    size_t size;
     
public:
 
    //Standard Konstruktor zum erstellen einer leeren Liste
    FilterableList()
    {
        first = 0;
        last = 0;
        size = 0;
    }
 
    //Destruktor zum lφschen der Liste
    ~FilterableList()
    {
        removeFirst();
    }
 
    //Filtert die Liste bezόglich der Elemente
   // FilterableList<type> filter (Func<type, boolean> l){
         
        //Todo.. Lambda quatsch mόsst ich grad selber nachschauen und muss essen gehen ;P
    //}
     
    //Funktion um zu ermitteln ob die Liste leer ist
    bool empty()
    {
        if( first == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
 
    //Funktion um ein Element (@param value) hinten an die Liste anzufόgen
    void add(type value)
    {
        // Ein neues Listenelemente fόr den Wert erzeugen.
        // Das neue Element hat keinen Nachfolger, aber einen Vorgδnger
        LE<type>* newLE = new LE<type>(value,last);
 
        if(first == 0)
        { 
            first = newLE;
			cout << "added first : " << value << endl;
        }
        else
        {
            last->next = newLE;
			cout << "added next : " << value << endl;
        }
         
        last = newLE;
        size++;
    }
 
    size_t getSize()
    {
        return size;
    }
 
     
    //Funktion um ein Element, das vorne an der Liste steht, zu lφschen
    void removeFirst()
    {
        if(first != 0)
        {
            LE<type>* nextFirstLE = first->next;
 
            delete first;
 
            first = nextFirstLE;
 
            if(first == 0)
            {
                last = 0;
            }
        }
    }
 
    //Funktion um ein Element, das hinten an der Liste steht, zu lφschen
    void removeLast()
    {
        if(first != 0)
        {
            LE* nextLastLE = last->prev; 
 
            delete last;
 
            last = nextLastLE;
 
            if(first == 0)
            {
                last = 0;
            }
        }
    }
 
     
    //Funktion um ein Element an Stelle #index zu lφschen
    void remove(unsigned int index){
         
        unsigned int count = 0;
        LE<type>* actualE = first;
         
        while(count < index)
        {
            actualE = actualE->next;
            count++;
        }
         
        if((actualE->prev == 0) & (actualE->next == 0))
        {
            first = 0;
            last = 0;
        }
        else
        {
            if(actualE->prev != 0){
                actualE->prev->next = actualE->next;
            }
            if(actualE->next != 0){
                actualE->next->prev = actualE->prev;
            }
            if(actualE == first){
                first = actualE->next;
            }
            if(actualE == last){
                last = actualE->prev;
            }
        }
        size--;
        delete actualE;
    }
 
    //Funktion zur ermittlung der grφίe der Liste
    int getSize() const
    {
        LE *listRunner = first;
        int size = 0;
 
        while (listRunner != 0) {
            size++;
            listRunner = listRunner->next;
        }
 
        return size;
    }
 
     
    //Methode zur Rόckgabe des LE am angegebenen Index
    type& has(type valueWanted)
    {
        LE<type>* listRunner = first;
        unsigned int counter = 0;
        boolean hasE = false;
 
        while (listRunner != 0 && counter < size) {
            counter++;
            if(listRunner->value == valueWanted){
                counter = getSize();
            }else{
                listRunner = listRunner->next;
            }
             
        }
 
        return hasE;    
    }
     
     
    //Methode zur Rόckgabe des LE am angegebenen Index
    type& get(unsigned int index)
    {
        LE<type>* listRunner = first;
        unsigned int counter = 0;
 
        while (listRunner != 0 && counter < index) {
            counter++;
            listRunner = listRunner->next;
        }
 
        return listRunner->value;    
    }

	//generate random Floats ---> neue Methde finden, die immer neue Zahlen generiert!!!!
	float numbers() {
		float r = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000);
		return r;
	}

	std::string randomString() {
		std::string word = "";
		char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
		int wordlenght = rand() % 20;
		for (int i = 0; i < wordlenght; ++i) {
			word += alphabet[rand() % (sizeof(alphabet) - 1)];
		}
		return word;
	}
 
};
 
#endif //_LISTE_INCLUDED

