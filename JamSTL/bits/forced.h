#pragma once

#ifndef JAMSTL_FORCED_H
#define JAMSTL_FORCED_H

namespace jamstl {
    class forced {
        virtual void pureDummy() = 0;

        virtual ~forced() throw();

    };

    
}


#endif