enter_region:
    TSL_REGISTER,LOCK
    CMP REGISTER.#0
    JNE enter_region
    RET
    
leave_region:
    MOVE LOCK,#0
    RET

