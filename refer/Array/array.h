#ifndef F77C72E2_9447_4248_8CA4_931620D78CAB
#define F77C72E2_9447_4248_8CA4_931620D78CAB

template <typename T>
class Array
{
private:
    T *n;
    unsigned long long size;

public:
    Array();
    Array(T *);
    Array(int, T);
    Array(Array);
    ~Array();

    int length() { return size; }
};

#endif /* F77C72E2_9447_4248_8CA4_931620D78CAB */
