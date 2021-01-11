!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Prog 4 solves the Traveling Salesman problem from a data file
! input, and outputs the cities, the total distances, the best
! outcome, and the amount of permutations required.
!      
! Prog 4
! Dalton Tarde 
! CS-320 Section 1
! November 3, 2020 
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
PROGRAM P4

IMPLICIT NONE

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Variable declarations

INTEGER, DIMENSION(:,:), ALLOCATABLE :: d_table                            ! 2D Integer Array for distances

TYPE city
    CHARACTER(20) :: name                                                  ! name is used in recursive function 
END TYPE 
TYPE(city), DIMENSION(:), ALLOCATABLE :: city_list                         ! 1D Character Array for cities 
INTEGER, DIMENSION(:), ALLOCATABLE :: path                                 ! 1D Integer array for path
INTEGER, DIMENSION(:), ALLOCATABLE :: best_path                            ! 1D Integer array for optimal path 

INTEGER :: i, j, best_distance, distance, count, error_case,  permutations ! Integer declarations for required variables 

CHARACTER(20) :: filename                                                  ! File I/O 

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Open the file and read number of cities

PRINT "(a30)", "Program #4, cssc2670, Dalton Tarde"
PRINT * 

PRINT *,"Enter filename: " 
READ *, filename

open(UNIT = 9, FILE = filename, FORM="FORMATTED", STATUS = "OLD", ACTION = "READ", IOSTAT = error_case) 

IF(error_case /= 0) THEN 
    PRINT *, "Could not open file"                      
    STOP 
END IF
READ (UNIT = 9, FMT = 100) count    ! Reads in amt of cities from input file    

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Allocate memory for all needed arrays

ALLOCATE(d_table(1:count, 1:count)) 
ALLOCATE(city_list(1:count)) 
ALLOCATE(path(1:count))
ALLOCATE(best_path(1:count)) 
  
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Fill in arrays from data file

DO i = 1, count 
    path(i) = i
    best_path(i) = i
    READ(UNIT = 9, FMT = 200) city_list(i) 
    DO j = 1, count
        READ (UNIT = 9, FMT = 100) d_table(i, j) 
    END DO
END DO 

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Use recursion to find minimal distance
best_distance = 100000          ! initialzied for comparision purposes 
call permute(2,count)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Print formatted output

PRINT *
DO i = 1, count
        IF (i /= count) THEN 
            PRINT *, city_list(best_path(i)), " to " , city_list(best_path(i+1)), & 
                &" -- ", d_table(best_path(i),best_path(i+1)), " miles" 
        ELSE
            PRINT *, city_list(best_path(i)), " to " , city_list(best_path(1)), &  
                &" -- ", d_table(best_path(i),best_path(1)), " miles"
        END IF 
END DO 
PRINT *
PRINT *, "Best distance is: ", best_distance
PRINT *, "Number of permutations: ", permutations

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Format labels

100 FORMAT (I6)
200 FORMAT (A)

CONTAINS
!Permute function

RECURSIVE SUBROUTINE permute(first, last)
! Declare intent of parameter variables
    IMPLICIT NONE 
        INTEGER :: i, temp, first, last
            IF(first == last)  THEN
                distance = d_table(1,path(2))
                PRINT *, city_list(1)%name, city_list(path(2))%name, " ", d_table(1, path(2))
                DO i=2, last-1           
                    distance = distance + d_table(path(i),path(i+1)) 
                    print *, city_list(path(i))%name, " ", city_list(path(i+1))%name,&
                    d_table(path(i),path(i+1)) 
                END DO
                distance = distance + d_table(path(last),path(1))
                PRINT *, city_list(path(last))%name," ",city_list(path(1))%name, &
                    d_table(path(last),path(1))
                PRINT *, "Distance is ",distance
                PRINT *
                permutations = permutations + 1
                IF(distance < best_distance) THEN
                    best_distance = distance
                    DO i=2, count
                        best_path(i) = path(i)
                    END DO
                END IF
                
            ELSE
                DO i=first, last
                    temp = path(first)
                    path(first) = path(i)
                    path(i) = temp

                    call permute(first+1,last)
            
                    temp = path(first)
                    path(first) = path(i)
                    path(i) = temp
                END DO
            END IF
    END SUBROUTINE permute 

END PROGRAM P4
