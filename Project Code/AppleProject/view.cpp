#include "view.h"

View* View::_instance = 0;

View::View()
{

}

View* View::Instance(){
    if(_instance == 0) _instace = View();
    return instance;
}

