#include"Card.h"

Card::Card(Shape shape, int _nb) : shape(shape),rank(_nb){
	
}

void Card::display() {

	cout << rank << " de " << shape << endl;

}