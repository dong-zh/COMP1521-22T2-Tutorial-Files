	.text
main:
	# i = t0
	# j = t1
main__i_init:
	li	$t0, 1
main__i_cond:
	bgt	$t0, 10, main__i_end	# if (i > 10) goto i_end
main__i_body:
main__j_init:
	li	$t1, 0
main__j_cond:
	bge	$t1, $t0, main__j_end	# if (j >= i) goto j_end
main__j_body:
	# print char syscall (code 11)
	li	$v0, 11
	li	$a0, '*'
	syscall
main__j_step:
	addi	$t1, $t1, 1
	b	main__j_cond
main__j_end:
	# print char syscall (code 11)
	li	$v0, 11
	li	$a0, '\n'
	syscall

main__i_step:
	addi	$t0, $t0, 1
	b	main__i_cond
main__i_end:

	jr	$ra
