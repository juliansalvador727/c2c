import subprocess as sp
import sys

# Choose the Python executable based on OS
python_cmd = "python3" if sys.platform != "win32" else "python"

scripts = ["data/borders.py", "data/country_code.py", "data/check.py", "data/matrix.py", "data/matrix_country_code.py"]

for script in scripts:
    print(f"Running {script}...")
    result = sp.run([python_cmd, script], capture_output=True, text=True)
    if result.returncode == 0:
        print(f"{script} completed successfully.")
    else:
        print(f"{script} failed with error:\n{result.stderr}")
        break 

print("\n✅ All tasks complete (if no errors above).")