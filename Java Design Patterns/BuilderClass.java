public class BuilderClass {
  private String firstName;
  private String lastName;
  private int age;

  public BuilderClass(String fName, String lName, int ageVal) {
    this.setFirstName(fName);
    this.setLastName(lName);
    this.setAge(ageVal);
  }

  /**
   * @return the age
   */
  public int getAge() {
    return age;
  }

  /**
   * @param age the age to set
   */
  public void setAge(int age) {
    this.age = age;
  }

  /**
   * @return the lastName
   */
  public String getLastName() {
    return lastName;
  }

  /**
   * @param lastName the lastName to set
   */
  public void setLastName(String lastName) {
    this.lastName = lastName;
  }

  /**
   * @return the firstName
   */
  public String getFirstName() {
    return firstName;
  }

  /**
   * @param firstName the firstName to set
   */
  public void setFirstName(String firstName) {
    this.firstName = firstName;
  }

  public static class Builder {
    private String firstName;
    private String lastName;
    private int age;

    public Builder setFirstName(String fName) {
      this.firstName = fName;
      return this;
    }

    /**
     * @return the age
     */
    public int getAge() {
      return age;
    }

    /**
     * @return the lastName
     */
    public String getLastName() {
      return lastName;
    }

    /**
     * @return the firstName
     */
    public String getFirstName() {
      return firstName;
    }

    public Builder setLastName(String lName) {
      this.lastName = lName;
      return this;
    }

    public Builder setAge(int ageVal) {
      this.age = ageVal;
      return this;
    }

    public BuilderClass build() {
      return new BuilderClass(fName, lName, ageVal);
    }
  }
}

// Usage
// BuilderClass builder = new BuilderClass.Build()
// .setFirstName("blah")
// .setLastName("blah")
// .setAge(26)
// .build();
