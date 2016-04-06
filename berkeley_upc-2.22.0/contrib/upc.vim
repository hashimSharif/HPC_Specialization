" Vim syntax file
" Language:	UPC
"
" Installation:
" 1) This file should be copied to your vim syntax directory,
"    which is typically $HOME/.vim/syntax/
" 2) The following three lines (w/o the leading quote) should be added
"    to your filetype.vim file (typically $HOME/.vim/filetype.vim)
"augroup filetypedetect
"  au! BufRead,BufNewFile *.upc   setfiletype upc
"augroup END
"
" If you wish to install this gloablly, please see your vim documentation
" for help locating the correct directory to use in place of  $HOME/.vim/

so $VIMRUNTIME/syntax/c.vim

syn match	cStorageClass	display /\<shared\>/
syn match	cStorageClass	display /\<shared\W\+\[.*\]/
syn keyword	cStorageClass	strict relaxed
syn keyword	cRepeat		upc_forall
syn keyword	cConstant	THREADS MYTHREAD UPC_MAX_BLOCK_SIZE
syn keyword	cOperator	upc_localsizeof upc_blocksizeof upc_elemsizeof
" strictly speaking the next line contains library functions, not operators.
syn keyword	cOperator	upc_phaseof upc_threadof upc_addrfield upc_resetphase upc_affinitysize

" We don't do anything with these classes by default
syn keyword	upcAlloc	upc_local_alloc upc_global_alloc upc_all_alloc upc_free upc_all_free
syn keyword	upcLockAlloc	upc_global_lock_alloc upc_all_lock_alloc upc_lock_free upc_all_lock_free
syn keyword	upcLocks	upc_lock upc_lock_attempt upc_unlock
syn keyword	upcString	upc_memcpy upc_memget upc_memput upc_memset
syn keyword	upcSync		upc_barrier upc_notify upc_wait upc_fence
syn keyword	upcExit		upc_global_exit

