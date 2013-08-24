if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <F9> :!./test
imap <F8> :cn
imap <F7> :cp
imap <F6> :make clean
imap <F5> :make :copen
imap <F4> 
imap <F3> 	
imap <F2> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q . :TlistUpdate
noremap  h
noremap <NL> j
noremap  k
noremap  l
map \mbt <Plug>TMiniBufExplorer
map \mbu <Plug>UMiniBufExplorer
map \mbc <Plug>CMiniBufExplorer
map \mbe <Plug>MiniBufExplorer
nmap \a <Plug>ToggleAutoCloseMappings
nmap gx <Plug>NetrwBrowseX
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
noremap <C-Right> l
noremap <C-Left> h
noremap <C-Up> k
noremap <C-Down> j
map <F9> :!./test
map <F8> :cn
map <F7> :cp
map <F6> :make clean
map <F5> :make :copen
map <F2> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q . :TlistUpdate
inoremap <expr>  omni#cpp#maycomplete#Complete()
inoremap <silent> OC <Right>
inoremap <expr> . omni#cpp#maycomplete#Dot()
inoremap <expr> : omni#cpp#maycomplete#Scope()
inoremap <expr> > omni#cpp#maycomplete#Arrow()
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set background=dark
set backspace=indent,eol,start
set completeopt=menuone
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set history=50
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set omnifunc=omni#cpp#complete#Main
set printoptions=paper:letter
set ruler
set runtimepath=~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after
set shiftwidth=4
set showcmd
set showmatch
set smartcase
set softtabstop=4
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=4
set tags=./tags,./TAGS,tags,TAGS,~/.vim/tags/cpp/tags
set whichwrap=b,s,<,>,[,]
" vim: set ft=vim :
