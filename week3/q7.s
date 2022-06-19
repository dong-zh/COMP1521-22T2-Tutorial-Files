	.data
numbers:
	.word	0, 1, 2, -3, 4, -5, 6, -7, 8, 9

	.text
main:
	# t0 = i
	# t1 = numbers[i] offset
	# t2 = numbers[i]

main__i_init:
	li	$t0, 0
main__i_cond:
	bge	$t0, 10, main__i_end
main__i_body:
	mul	$t1, $t0, 4
	lw	$t2, numbers($t1)
	bgez	$t2, main__numbers_phi
main__numbers_lt_0:
	add	$t2, $t2, 42
	sw	$t2, numbers($t1)
main__numbers_phi:
main__i_step:
	add	$t0, $t0, 1
	j	main__i_cond
main__i_end:

	jr	$ra
