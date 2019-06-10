#ifndef ITEMLOCKABLE_H
#define ITEMLOCKABLE_H


class ItemLockable
{
public:
    ItemLockable();
    char param;
    bool isFree();
    void unsafe_lock();
    void safe_lock();
    void unlock();
};

#endif // ITEMLOCKABLE_H