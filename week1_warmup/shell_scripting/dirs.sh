mkdir root
cd root
mkdir dir1
mkdir dir2
mkdir dir3
mkdir dir4
mkdir dir5
cd dir1
touch file1
cat > file1 <<- "EOF"
1
EOF
touch file2
cat > file2 <<- "EOF"
2
2
EOF
touch file3
cat > file3 <<- "EOF"
3
3
3
EOF
touch file4
cat > file4 <<- "EOF"
4
4
4
4
EOF
cd ..
cd dir2
touch file1
cat > file1 <<- "EOF"
1
EOF
touch file2
cat > file2 <<- "EOF"
2
2
EOF
touch file3
cat > file3 <<- "EOF"
3
3
3
EOF
touch file4
cat > file4 <<- "EOF"
4
4
4
4
EOF
cd ..
cd dir3
touch file1
cat > file1 <<- "EOF"
1
EOF
touch file2
cat > file2 <<- "EOF"
2
2
EOF
touch file3
cat > file3 <<- "EOF"
3
3
3
EOF
touch file4
cat > file4 <<- "EOF"
4
4
4
4
EOF
cd ..
cd dir4
touch file1
cat > file1 <<- "EOF"
1
EOF
touch file2
cat > file2 <<- "EOF"
2
2
EOF
touch file3
cat > file3 <<- "EOF"
3
3
3
EOF
touch file4
cat > file4 <<- "EOF"
4
4
4
4
EOF
cd ..
cd dir5
touch file1
cat > file1 <<- "EOF"
1
EOF
touch file2
cat > file2 <<- "EOF"
2
2
EOF
touch file3
cat > file3 <<- "EOF"
3
3
3
EOF
touch file4
cat > file4 <<- "EOF"
4
4
4
4
EOF

