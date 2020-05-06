#include"Card.h"

Card::Card(Shape shape, int _nb) : shape(shape),rank(_nb){
	
}

void Card::display() {

	switch (rank) {
	case 13:
		cout << "Roi" << " de " << map(shape) << endl;
		break;
	case 12:
		cout << "Reine" << " de " << map(shape) << endl;
		break;
	case 11:
		cout << "Valet" << " de " << map(shape) << endl;
		break;
	default:
		cout << rank << " de " << map(shape) << endl;
		break;
	}
	

}