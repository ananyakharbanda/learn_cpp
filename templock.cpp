template<typename T>
class lock_guard{

    T lt_;

    lock_guard(T lt){
        lt.acquire();
        lt_ = lt;
    }

    ~lock_guard(){
        lt_.release()
    }
}


producer(){

    while(try_to_take_mutex) {
        take_mutex
        q.insert()
        release mutex
    }
}

consumer(){
    while(try_to_take_mutex){
        take mutex
        q.deque();
        release mutex)
}


int main() {
    std::thread consumer(pop);
    std::thread producer(push, "hi");
}
        






    
