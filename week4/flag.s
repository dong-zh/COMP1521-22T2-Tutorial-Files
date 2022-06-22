	.data
flag:
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte	'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte	'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

flag_pole:
	.asciiz	"|\n|\n|\n|\n|\n|\n|\n|\n"

# Constants
NUM_ROWS = 6
NUM_COLS = 12

	.text

# ------------------------------------------------------------------------------
#                                 Main Function
# ------------------------------------------------------------------------------
main:
main__prologue:
	begin
	push	$ra

main__body:
	# Print the flag
	jal	print_flag

	# Print the flag pole
	# print string syscall (code 4)
	li	$v0, 4
	la	$a0, flag_pole
	syscall

	# Print the hill
	li	$a0, 16
	jal	print_hill

main__epilogue:
	pop	$ra
	end

	jr	$ra

# ------------------------------------------------------------------------------
#                              Print Flag Function
# ------------------------------------------------------------------------------
print_flag:
print_flag__prologue:
	begin
	push	$ra
	push	$s0

print_flag__body:
	# s0 = row
print_flag__row_init:
	li	$s0, 0		# row = 0
print_flag__row_cond:
	bge	$s0, NUM_ROWS, print_flag__row_end
print_flag__row_body:
	move	$a0, $s0
	jal	print_row

print_flag__row_step:
	addi	$s0, $s0, 1
	b	print_flag__row_cond
print_flag__row_end:

print_flag__epilogue:
	pop	$s0
	pop	$ra
	end
	jr	$ra

# ------------------------------------------------------------------------------
#                              Print Row Function
# ------------------------------------------------------------------------------
print_row:
	# t3 = row
	# t0 = col
	# t2 = offset calculation
	# t4 = character to print ('*')

	move	$t3, $a0

print_row__col_init:
	li	$t0, 0		# col = 0
print_row__col_cond:
	bge	$t0, NUM_COLS, print_row__col_end
print_row__col_body:
	# base + (i * num_cols + j) * sizeof each element
	# flag + (t3 * NUM_COLS + t0) * 1
	mul	$t2, $t3, NUM_COLS
	add	$t2, $t2, $t0
	lb	$t4, flag($t2)	# load flag[row][col] into t4

	# print char syscall (code 11)
	li	$v0, 11
	move	$a0, $t4
	syscall

print_row__col_step:
	addi	$t0, $t0, 1
	b	print_row__col_cond
print_row__col_end:

	# print char syscall (code 11)
	li	$v0, 11
	li	$a0, '\n'
	syscall

	jr	$ra

# ------------------------------------------------------------------------------
#                              Print Hill Function
# ------------------------------------------------------------------------------
print_hill:
print_hill__prologue:
	begin
	push	$ra
	push	$s0
print_hill__body:
	# t0 = i
	# s0 = height
	move	$s0, $a0	# s0 = height

	# Recursion terminating case
	blez	$s0, print_hill__epilogue

	# Recursive call
	sub	$a0, $s0, 1
	jal	print_hill

print_hill__i_init:
	li	$t0, 0		# i = 0
print_hill__i_cond:
	bge	$t0, $s0, print_hill__i_end
print_hill__i_body:
	# put char syscall (code 11)
	li	$v0, 11
	li	$a0, '*'
	syscall

print_hill__i_step:
	addi	$t0, $t0, 1
	b	print_hill__i_cond
print_hill__i_end:
	# put char syscall (code 11)
	li	$v0, 11
	li	$a0, '\n'
	syscall

print_hill__epilogue:
	pop	$s0
	pop	$ra
	end

	jr	$ra
