import ctypes
import pathlib
import time
from numpy.linalg import det

def compareMethods(A_ctype, A_list):
    tic = time.time()
    det_computeDeterminant = c_lib.computeDeterminant(A_ctype, len(A_list))
    toc = time.time() - tic
    print("det_computeDeterminant = " + str(det_computeDeterminant))
    print("computeDeterminant: " + str(toc) + " sec\n" )

    tic = time.time()
    det_numpy = det(A_list)
    toc = time.time() - tic
    print("det_numpy = " + str(det_numpy))
    print("numpy.linalg.det: " + str(toc) + " sec\n")


if __name__ == "__main__":
    # Load the shared library into ctypes
    libname = pathlib.Path().absolute() / "my_lib/build/libmy_lib.so"
    c_lib = ctypes.CDLL(libname)
    
    # ### fake function without class without pointers
    # A = 3.5
    # c_lib.computeDeterminant.argtypes = (ctypes.c_double,)
    # c_lib.computeDeterminant.restype = ctypes.c_double
    # determinant = c_lib.computeDeterminant(A)

    # ### det function without armadillo without class without pointers
    # A_list = [  [1,2,3],
    #             [0,2,0],
    #             [0,0,5]]
    # A = (ctypes.c_double * len(A_list))*len(A_list)
    # A_ctype = A()

    # for i in range(len(A_list)):
    #     for j in range(len(A_list[i])):
    #         A_ctype[i][j] = A_list[i][j]

    # c_lib.computeDeterminant.argtypes = ((ctypes.c_double * 3)*3,)
    # c_lib.computeDeterminant.restype = ctypes.c_double
    # determinant = c_lib.computeDeterminant(A_ctype)
    # print(determinant)

    ### recursive determinant
    A_list = [  [1,1,1,1],
                [1,2,3,4],
                [0,1,0,1],
                [0,1,1,1]]
    A = (ctypes.c_double * 10)*10
    A_ctype = A()

    for i in range(len(A_list)):
        for j in range(len(A_list[i])):
            A_ctype[i][j] = A_list[i][j]

    c_lib.computeDeterminant.argtypes = ((ctypes.c_double * 10)*10,)
    c_lib.computeDeterminant.restype = ctypes.c_double
    determinant = c_lib.computeDeterminant(A_ctype, len(A_list))
    print(determinant)

    compareMethods(A_ctype, A_list) # method comparing computeDeterminant and numpy.linalg.det
                                    # A_ctype is C double type matrix and A_list is a python list of list
