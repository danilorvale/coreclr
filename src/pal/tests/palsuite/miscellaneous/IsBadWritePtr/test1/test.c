//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information. 
//

/*============================================================
**
** Source: test.c
**
** Purpose: IsBadWritePtr() function
**
**
**=========================================================*/

#include <palsuite.h>

#define MEMORY_AMOUNT 16

int __cdecl main(int argc, char *argv[]) {
    
    void * TestingPointer = NULL;
    BOOL ResultValue = 0;

    /*
     * Initialize the PAL and return FAILURE if this fails
     */

    if(0 != (PAL_Initialize(argc, argv)))
    {
        return FAIL;
    }
  
    TestingPointer = malloc(MEMORY_AMOUNT);
    if ( TestingPointer == NULL )
    {
	Fail("ERROR: Failed to allocate memory for TestingPointer pointer. "
             "Can't properly exec test case without this.\n");
    }


    /* This should be writeable, return 0 */
    ResultValue = IsBadWritePtr(TestingPointer,MEMORY_AMOUNT);

    if(ResultValue != 0) 
    {
	free(TestingPointer);

        Fail("ERROR: Returned %d when 0 should have been returned, checking "
             "to see if writable memory is unwriteable.\n",ResultValue);
    }

    free(TestingPointer);
  
    /* This should be !writeable, return nonezero */
    TestingPointer = (void*)0x08; /* non writeable address */
    ResultValue = IsBadWritePtr(TestingPointer,sizeof(int));
    
    if(ResultValue == 0) 
    {
        Fail("ERROR: Returned %d when nonezero should have been returned, "
             "checking to see if unwriteable memory  is writeable.\n",
             ResultValue);
    }
  
    /* This should be !writeable, return Nonezero */
    ResultValue = IsBadWritePtr(NULL,MEMORY_AMOUNT);

    if(ResultValue == 0) 
    {
        Fail("ERROR: Returned %d when nonezero should have been "
	     "returned,checking "
             "to see if a NULL pointer is writeable.\n",
             ResultValue);
    }
    
    PAL_Terminate();
    return PASS;
}




