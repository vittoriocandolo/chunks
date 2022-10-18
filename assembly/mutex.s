mutex_lock:
    TSL REGISTER,MUTEX
    CMP REGISTER.#0
    JZE ok
    CALL thread_yield
    JMP mutex_lock
ok: RET

mutex_unlock:
    MOVE MUTEX,#0
    RET

