# For UNIX-based operating systems

echo "Configurating project"
cmake -S . -B build
echo "Running testing suite..."
cmake --build build --target testproject
echo "Running project..."
cmake --build build --target run