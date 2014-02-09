class TRecursiveMutex
{
public:
    TRecursiveMutex();
    ~TRecursiveMutex();
 
    void Acquire();
    void Release();
 
private:
    RMutex iMutex;
    TThreadId iOwner;
    TInt iCount;
};
 
TRecursiveMutex::TRecursiveMutex() : iCount(0)
{
    iMutex.CreateLocal();
}
 
TRecursiveMutex::~TRecursiveMutex()
{
    iMutex.Close();
}
 
void TRecursiveMutex::Acquire()
{
    TThreadId id = RThread().Id();
    if (iOwner == id)
    {
        ++iCount;
    }
    else
    {
        iMutex.Wait();
        iCount = 1;
        iOwner = id;
    }
}
 
void TRecursiveMutex::Release()
{
    if (--iCount == 0)
    {
        iOwner = 0;
        iMutex.Signal();
    }
}
