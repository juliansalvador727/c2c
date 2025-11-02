import subprocess as sp

scripts = ["data/borders.py", "data/country_code.py", "data/check.py", "data/matrix.py", "data/matrix_country_code.py"]

for script in scripts:
    print(f"\Running {script}...")
    result = sp.run(["python", script], capture_output=True, text=True)
    if result.returncode == 0:
        print(f"{script} completed successfully.")
    else:
        print(f"{script} failed with error:\n{result.stderr}")
        break 

print("\n✅ All tasks complete (if no errors above).")