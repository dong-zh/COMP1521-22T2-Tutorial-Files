	.data
prompt:
	.asciiz	"Enter a number: "
medium:
	.asciiz	"medium\n"
small_big:
	.asciiz	"small/big\n"

	.text
main:
	# x = t0
	# print str syscall (code 4)
	li	$v0, 4
	la	$a0, prompt
	syscall

	# read int syscall (code 5)
	li	$v0, 5
	syscall
	move	$t0, $v0	# t0 = x

	ble	$t0, 100, main__x_small_big	# if (t0 <= 100) goto x_small_big
	bge	$t0, 1000, main__x_small_big	# if (t0 >= 1000) goto x_small_big
main__x_medium:
	# print str syscall (code 4)
	li	$v0, 4
	la	$a0, medium
	syscall
	b	main__x_phi
main__x_small_big:
	# print str syscall (code 4)
	li	$v0, 4
	la	$a0, small_big
	syscall

main__x_phi:

	jr	$ra
