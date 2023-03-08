" ==================== Editor behavior ====================
set number
set relativenumber
"set cursorline
set wrap

set expandtab
set tabstop=2
set shiftwidth=2
set softtabstop=2

set ignorecase
set smartcase
set notimeout
set mouse=a

set autochdir
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

" ==================== Basic Mappings ====================
"===== Insert Mode Cursor Movement================
imap jk <Esc>
imap kj <Esc>

let mapleader=" "
noremap ; :
nnoremap Q :q<CR>
"nnoremap s <Nop>
nnoremap S :w<CR>
nnoremap R :source $MYVIMRC<CR>

" Open the vimrc file anytime
" (next 2 line is another way)
"nnoremap <space>rl :so ~/.config/nvim/init.vim<CR>
"nnoremap <space>rc :e ~/.config/nvim/init.vim<CR>
nnoremap <LEADER>rc :e $HOME/.config/nvim/init.vim<CR>
nnoremap <LEADER>rv :e .nvimrc<CR>
augroup NVIMRC
    autocmd!
    autocmd BufWritePost *.nvimrc exec ":so %"
augroup END

" Copy to system clipboard
vnoremap Y "+y

" Search
noremap = nzz
noremap - Nzz
noremap <LEADER><CR> :nohlsearch<CR>

" ==================== Cursor Movement ====================
"     ^
"     u
" < n   i >
"     e
"     v
"noremap <silent> i k
"noremap <silent> j h
"noremap <silent> k j

" U/E keys for 5 times u/e (faster navigation)
noremap <silent> J 5j
noremap <silent> K 5k

" J key: go to the start of the line
noremap <silent> H 0
" L key: go to the end of the line
noremap <silent> L $

" Faster in-line navigation
noremap W 5w
noremap B 5b

" set h (same as n, cursor left) to 'end of word'
"noremap h e

" Ctrl + I or K will move up/down the view port without moving the cursor
noremap <C-J> 5<C-y>
noremap <C-K> 5<C-e>

" ==================== Window management ====================
" Use <space> + new arrow keys for moving the cursor around windows
noremap <LEADER>w <C-w>w
noremap <LEADER>i <C-w>k
noremap <LEADER>k <C-w>j
noremap <LEADER>j <C-w>h
noremap <LEADER>l <C-w>l
noremap qf <C-w>o

" Disable the default s key
" noremap s <nop>

" split the screens to up (horizontal), down (horizontal), left (vertical), right (vertical)
"noremap si :set nosplitbelow<CR>:split<CR>:set splitbelow<CR>
"noremap sk :set splitbelow<CR>:split<CR>
"noremap sj :set nosplitright<CR>:vsplit<CR>:set splitright<CR>
"noremap sl :set splitright<CR>:vsplit<CR>

" Resize splits with arrow keys
noremap <up> :res +5<CR>
noremap <down> :res -5<CR>
noremap <left> :vertical resize-5<CR>
noremap <right> :vertical resize+5<CR>

" Place the two screens up and down
"noremap sh <C-w>t<C-w>K
" Place the two screens side by side
"noremap sv <C-w>t<C-w>H

" Rotate screens
"noremap srh <C-w>b<C-w>K
"noremap srv <C-w>b<C-w>H

" Press <SPACE> + q to close the window below the current window
"noremap <LEADER>q <C-w>j:q<CR>


" ==================== Tab management ====================
" Create a new tab with ti
noremap ti :tabe<CR>
noremap tI :tab split<CR>
" Move around tabs with tj and tl
noremap tj :-tabnext<CR>
noremap tl :+tabnext<CR>
" Move the tabs with tmj and tml
noremap tmj :-tabmove<CR>
noremap tml :+tabmove<CR>

" ==================== Other useful stuff ====================
" Opening a terminal window
"noremap <LEADER>/ :set splitbelow<CR>:split<CR>:res +10<CR>:term<CR>
" Press space twice to jump to the next '<++>' and edit it
noremap <LEADER><LEADER> <Esc>/<++><CR>:nohlsearch<CR>c4l
" Spelling Check with <space>sc
noremap <LEADER>sc :set spell!<CR>
" Press ` to change case (instead of ~)
noremap ` ~
noremap <C-c> zz
" Auto change directory to current dir
autocmd BufEnter * silent! lcd %:p:h
" Call figlet
noremap tx :r !figlet 
" find and replace
noremap \s :%s//g<left><left>
" set wrap
noremap <LEADER>sw :set wrap<CR>
" press f10 to show hlgroup
function! SynGroup()
	let l:s = synID(line('.'), col('.'), 1)
	echo synIDattr(l:s, 'name') . ' -> ' . synIDattr(synIDtrans(l:s), 'name')
endfun
map <F10> :call SynGroup()<CR>

" Compile function
noremap r :call CompileRunGcc()<CR>
func! CompileRunGcc()
	exec "w"
	if &filetype == 'c'
	  if !isdirectory("build")
			execute "!mkdir build"
		endif
    set splitbelow
		:sp
		:res -5
		"term gcc % -o %< && time ./%<
		term gcc % -o build/%< && time ./build/%<
  elseif &filetype == 'cpp'
		set splitbelow
		exec "!g++ -std=c++11 % -Wall -o %<"
		:sp
		:res -15
		:term ./%<
	elseif &filetype == 'cs'
		set splitbelow
		silent! exec "!mcs %"
		:sp
		:res -5
		:term mono %<.exe
	elseif &filetype == 'java'
		set splitbelow
		:sp
		:res -5
		term javac % && time java %<
	elseif &filetype == 'sh'
		:!time bash %
	elseif &filetype == 'python'
		set splitbelow
		:sp
		:term python3 %
	elseif &filetype == 'html'
		silent! exec "!".g:mkdp_browser." % &"
	elseif &filetype == 'markdown'
		exec "InstantMarkdownPreview"
	elseif &filetype == 'tex'
		silent! exec "VimtexStop"
		silent! exec "VimtexCompile"
	elseif &filetype == 'dart'
		exec "CocCommand flutter.run -d ".g:flutter_default_device." ".g:flutter_run_args
		silent! exec "CocCommand flutter.dev.openDevLog"
	elseif &filetype == 'javascript'
		set splitbelow
		:sp
		:term export DEBUG="INFO,ERROR,WARNING"; node --trace-warnings .
	elseif &filetype == 'racket'
		set splitbelow
		:sp
		:res -5
		term racket %
	elseif &filetype == 'go'
		set splitbelow
		:sp
		:term go run .
	endif
endfunc

"===================== Auto load for first time uses ===================
if empty(glob($HOME.'/.config/nvim/autoload/plug.vim'))
	silent !curl -fLo $HOME/.config/nvim/autoload/plug.vim --create-dirs
				\ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
	autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif



" ==================== Install Plugins with Vim-Plug ===================
" ===  plugins  begin ===
call plug#begin('~/.config/nvim/plugged')

  " UI Beautification
  Plug 'mhinz/vim-startify'
  Plug 'luochen1990/rainbow'
  Plug 'wincent/terminus'

  " enhance editor
  Plug 'tomtom/tcomment_vim'
  Plug 'jiangmiao/auto-pairs'

  "Auto format
  Plug 'google/vim-maktaba'
  Plug 'google/vim-codefmt'
  Plug 'rhysd/vim-clang-format'

  " terminal
  Plug 'skywind3000/vim-terminal-help'

  "themes
  Plug 'ajmwagar/vim-deus'
  Plug 'Mofiqul/vscode.nvim'
  Plug 'mhartington/oceanic-next'
  Plug 'morhetz/gruvbox'

  " Undo Tree
  Plug 'mbbill/undotree'

  " Treesitter
  Plug 'nvim-treesitter/nvim-treesitter'
  Plug 'nvim-treesitter/playground'

  "Status line
  Plug 'vim-airline/vim-airline'
  Plug 'vim-airline/vim-airline-themes'

  "file explorer
  Plug 'preservim/nerdtree'

 " lsp
  Plug 'neoclide/coc.nvim', {'branch': 'release'}

call plug#end()


"======================= Configuations =================================

"========================== Themes ========================
if (has("termguicolors"))
 set termguicolors
endif
" ======================== Vim -deus ======================
  "set termguicolors " enable true colors support
  "let $NVIM_TUI_ENABLE_TRUE_COLOR=1
  "silent! color deus
  "hi NonText ctermfg=gray guifg=grey10


"======================= Mofiqul/vscode.nvim ==============
" Vim-Script:
  "set termguicolors
" For dark theme
  "let g:vscode_style = "dark"
" For light theme
  "let g:vscode_style = "light"
" Enable transparent background
  "let g:vscode_transparency = 1
" Enable italic comment
  "let g:vscode_italic_comment = 1
" Disable nvim-tree background color
  "let g:vscode_disable_nvimtree_bg = v:true
  "colorscheme vscode


" ======================== Vim -deus ======================
" Theme
syntax enable
let g:oceanic_next_terminal_bold = 1
let g:oceanic_next_terminal_italic = 1
colorscheme OceanicNext

"========================= Gruvbox =========================
"let g:gruvbox_(option) = '(value)'
let g:gruvbox_italic=1
  "colorscheme gruvbox


" ==================== Rainbow ============================
"set to 0 if you want to enable it later via :RainbowToggle
let g:rainbow_active = 1




"==================== Editor Enhancement ==================
" ==== tomtom/tcomment_vim ================================
let g:tcomment_textobject_inlinecomment = ''
nmap <LEADER>cn g>c
vmap <LEADER>cn g>
nmap <LEADER>cu g<c
vmap <LEADER>cu g<

"==== Auto pair ===========================================
"fly mode
"let g:AutoPairsFlyMode = 1

"==== Autoformat ==========================================
augroup autoformat_settings
  autocmd FileType bzl AutoFormatBuffer buildifier
  autocmd FileType c,cpp,proto,javascript,arduino AutoFormatBuffer clang-format
  autocmd FileType dart AutoFormatBuffer dartfmt
  autocmd FileType go AutoFormatBuffer gofmt
  autocmd FileType gn AutoFormatBuffer gn
  autocmd FileType html,css,sass,scss,less,json AutoFormatBuffer js-beautify
  autocmd FileType java AutoFormatBuffer google-java-format
  autocmd FileType python AutoFormatBuffer yapf
  " Alternative: autocmd FileType python AutoFormatBuffer autopep8
  autocmd FileType rust AutoFormatBuffer rustfmt
  autocmd FileType vue AutoFormatBuffer prettier
augroup END


"====================== Vim-airline ========================
let g:airline#extensions#tabline#enabled = 1
"let g:airline#extensions#tabline#left_sep = ' '
"let g:airline#extensions#tabline#left_alt_sep = '|'
"let g:airline#extensions#tabline#formatter = 'default'
"let g:airline_theme='oceanicnext'   



" ==================== nvim-treesitter ====================
"if g:nvim_plugins_installation_completed == 1
lua <<EOF
require'nvim-treesitter.configs'.setup {
	-- one of "all", "language", or a list of languages
	ensure_installed = {"typescript", "dart", "java", "c", "prisma", "bash"},
	highlight = {
		enable = true,              -- false will disable the whole extension
		disable = { "rust" },  -- list of language that will be disabled
	},
}
EOF
"endif


" ==================== Undotree ====================
noremap U :UndotreeToggle<CR>
let g:undotree_DiffAutoOpen = 1
let g:undotree_SetFocusWhenToggle = 1
let g:undotree_ShortIndicators = 1
let g:undotree_WindowLayout = 2
let g:undotree_DiffpanelHeight = 8
let g:undotree_SplitWidth = 24
function g:Undotree_CustomMap()
	nmap <buffer> u <plug>UndotreeNextState
	nmap <buffer> e <plug>UndotreePreviousState
	nmap <buffer> U 5<plug>UndotreeNextState
	nmap <buffer> E 5<plug>UndotreePreviousState
endfunc




" ==== neoclide/coc.nvim ====

" coc extensions
let g:coc_global_extensions = [
      \ 'coc-json',
      \ 'coc-tsserver',
      \ 'coc-css',
      \ 'coc-html',
      \ 'coc-vimlsp',
      \ 'coc-cmake',
      \ 'coc-highlight',
      \ 'coc-pyright'
      \ ]

set hidden
set updatetime=300
set shortmess+=c
set signcolumn=number

" <TAB> to select candidate forward or
" pump completion candidate
inoremap <silent><expr> <TAB>
      \ pumvisible() ? "\<C-n>" :
      \ <SID>check_back_space() ? "\<TAB>" :
      \ coc#refresh()
" <s-TAB> to select candidate backward
inoremap <expr><s-TAB> pumvisible() ? "\<C-p>" : "\<C-h>"
function! s:check_back_space() abort
  let col = col('.')-1
  return !col || getline('.')[col - 1] =~# '\s'
endfunction

"Use <c-space> or <c-o> to tigger completion
"inoremap <silent><expr> <c-space> coc#refresh()

" <CR> to comfirm selected candidate
" only when there's selected complete item
if exists('*complete_info')
  inoremap <silent><expr> <CR> complete_info(['selected'])['selected'] != -1 ? "\<C-y>" : "\<C-g>u\<CR>"
endif

"show_documentation
nnoremap <silent> <LEADER>h :call <SID>show_documentation()<CR>
function! <SID>show_documentation()
  if(index(['vim', 'help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  elseif (coc#rpc#ready())
    call CocActionAsync('doHover')
  else
    execute '!' . &keywordprg . " " . expand('<cword>')
  endif
endfunction

" highlight link CocHighlightText Visual
" autocmd CursorHold * silent call CocActionAsync('highlight')   " TODO

"rename
nmap <leader>rn <Plug>(coc-rename)
"Formating selected code
xmap <leader>f <Plug>(coc-format-selected)
command! -nargs=0 Format :call CocAction('format')

augroup mygroup
  autocmd!
  autocmd FileType typescript,json setl formatexpr=CocAction('formatSelected')
  autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')
augroup end

" diagnostic info , find the ERROR
nnoremap <silent><nowait> <LEADER>d :CocList diagnostics<CR> 
nmap <silent> <LEADER>- <Plug>(coc-diagnostic-prev)
nmap <silent> <LEADER>= <Plug>(coc-diagnostic-next)
nmap <LEADER>qf <Plug>(coc-fix-current)

" Remap <C-f> and <C-b> for scroll float windows/popups.
if has('nvim-0.4.0') || has('patch-8.2.0750')
  nnoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? coc#float#scroll(1) : "\<C-f>"
  nnoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? coc#float#scroll(0) : "\<C-b>"
  inoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? "\<C-r>=coc#float#scroll(1)\<CR>" : "\<Right>"
  inoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? "\<C-r>=coc#float#scroll(0)\<CR>" : "\<Left>"
  vnoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? coc#float#scroll(1) : "\<C-f>"
  vnoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? coc#float#scroll(0) : "\<C-b>"
endif

" statusline support
" set statusline^=%{coc#status()}%{get(b:,'coc_current_function','')}  "TODO

" GoTo code navigation.
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gD :tab sp<CR><Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)

function! s:generate_compile_commands()
  if empty(glob('CMakeLists.txt'))
    echo "Can't find CMakeLists.txt"
    return
  endif
  if empty(glob('.vscode'))
    execute 'silent !mkdir .vscode'
  endif
  execute '!cmake -DCMAKE_BUILD_TYPE=debug
      \ -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B .vscode'
endfunction
command! -nargs=0 Gcmake :call s:generate_compile_commands()
