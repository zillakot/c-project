recursive subroutine shortest_path(airport,stack,head,count,N,distances,shortestdistance,shortestroute)
  implicit none
  integer :: i,j,head,st=0,count,N
  integer :: stack(N)
  type(map_target) :: airport(N), shortestroute(N)
  real :: s,shortestdistance
  real :: distances(N,N)
  
  do i=2,N
   !Choose next point
  stack(head+1)=i

   !Check that point is not visited yet 
  do j=1,head
    if (stack(head+1)==stack(j)) st=1
  end do
  if (st==1) then 
	 st=0
  else
  
  !If point is visited jump over next statement
    !kutsutaan rekursiivista aliohjelmaa
    if (head < N-1) call shortest_path(airport,stack,head+1,count,N,distances,shortestdistance,shortestroute)
    !kun rekursio saavuttaa maksimisyvyyden (m=N-1) niin tulostetaan reitti, rekursion syvyys ja reitin pituus
    if (head == N-1) then
	  
	  count=count+1
	  !Calculate travelled distance
	  s=0
	  do j=1,N-1
         s=s+distances(stack(j),stack(j+1))
      enddo
      s=s+distances(stack(N),stack(1))
      
      if (s<shortestdistance) then
         shortestdistance=s
         write(*,*) s,stack
		 do j=1,N
	       shortestroute(j)=airport(stack(j)) 
	     enddo
	     
      end if
    end if
  endif
  enddo
end subroutine shortest_path