# Contributing to Student Information System

 To maintain high code quality and satisfy our project requirements, please follow these guidelines:

## 🌿 Branching Strategy
* All development should be done in `develop` or feature branches (e.g., `feature/database-setup`).
* **Direct pushes to `main` are strictly prohibited.**

## 📝 Semantic Commit Guidelines
We follow the semantic commit format to keep our history clean and organized:
* `feat:` for new features (e.g., `feat: add student search`)
* `fix:` for bug fixes (e.g., `fix: docker-compose port issue`)
* `docs:` for documentation changes (e.g., `docs: update manual`)
* `ci:` Changes to GitHub Actions or CI/CD scripts.
* `refactor:` for code changes that neither fix a bug nor add a feature.
* `chore:` Routine tasks like updating `.gitignore` or minor file cleanup.

## 🔄 Continuous Integration (CI) Rules
To ensure the stability of our application, we use GitHub Actions for automated testing:
* **Build Check:** Every Pull Request triggers an automated build check.
* **Passing Status:** A PR cannot be merged if the "C++ Build Check" fails (Red X).
* **Fixing Failures:** If a check fails, the author must fix the code until the check passes (Green Check).

## 🚀 Pull Request (PR) Process
1. Push your changes to your feature branch.
2. Open a PR against the `develop` branch.
3. Assign at least one teammate for **Peer Review**.
4. Once approved, the PR can be merged by the Project Manager.

## 🛠️ Task Management
* Ensure your task is moved to **"In Progress"** on the GitHub Project Board before starting.
* Link your PR to the relevant Issue (e.g., "Closes #1").
