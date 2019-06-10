#include "ItemLockable.h"

ItemLockable::ItemLockable()
{
    param=1;
}


bool ItemLockable::isFree(){
    return param%2==1;
}

void ItemLockable::unsafe_lock(){
    param*=2;
}

void ItemLockable::safe_lock(){
    if(isFree())
        param*=2;
}


void ItemLockable::unlock(){
    if(!isFree())
        param/=2;
}
