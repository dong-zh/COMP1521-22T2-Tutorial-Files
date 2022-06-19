	.data
numbers:
	.word	0, 1, 2, 3, 4, 5, 6, 7, 8, 9

	.text
	# t0 = i
	# t1 = x
	# t2 = y
	# t3 = offset for numbers[i]
	# t4 = offset for numbers[9 - i]
main:
main__i_init:
	li	$t0, 0		# i = 0
main__i_cond:
	bge	$t0, 5, main__i_end
main__i_body:
	# calculate offset for numbers[i]
	mul	$t3, $t0, 4	# t3 = i * 4
	# x = numbers[i]
	lw	$t1, numbers($t3)	# t1 = numbers[i]

	# calculate offset for numbers[9 - i]
	li	$t5, 9
	sub	$t4, $t5, $t0	# t4 = 9 - i
	mul	$t4, $t4, 4	# t4 = (9 - i) * 4
	# y = numbers[9 - i]
	lw	$t2, numbers($t4)	# t2 = numbers[9 - i]

	sw	$t2, numbers($t3)	# numbers[i] = y
	sw	$t1, numbers($t4)	# numbers[9 - i] = x
main__i_step:
	add	$t0, $t0, 1
	j	main__i_cond
main__i_end:

	jr	$ra
