rm -rf .git

#recreate the repos from the current content only
git init
git checkout -b main
git add .
git commit -m "reset commits"

#push to the github remote repos ensuring you overwrite history
git remote add origin https://github.com/rrossmiller/gsql-formatter.git
git push -u --force origin main
