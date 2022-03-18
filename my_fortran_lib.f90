module my_module
    implicit none
    contains
    function add_func(a, b) result (c)
      integer, intent(in) :: a, b
      integer :: c
      c = a+b
    end function add_func

    subroutine add_sub(a, b, c)
      integer, intent(in) :: a, b
      integer, intent(out) :: c
      c = a+b
    end subroutine add_sub

    ! not C-interoperable
    subroutine add_assumed_shape_mats(a, b, c)
      integer, intent(in), dimension(:, :) :: a, b
      integer, intent(out), dimension(:, :) :: c
      c = a+b
    end subroutine add_assumed_shape_mats

    ! C-interoperable
    subroutine add_explicit_shape_mats(a, b, c, ncol, nrow)
      integer, intent(in), dimension(ncol, nrow) :: a, b
      integer, intent(out), dimension(ncol, nrow) :: c
      integer, intent(in) :: ncol, nrow
      call add_assumed_shape_mats(a, b, c)
    end subroutine add_explicit_shape_mats
end module my_module
